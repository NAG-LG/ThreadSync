#include "ThreadPool.h"

ThreadPool::ThreadPool(int threadCount):thread_Count_(threadCount),
										is_not_exit_threads(true),
										current_Pool_Status_(IDLE){
}

ThreadPool::~ThreadPool()
{
	for (auto& thread_handle : threads_Vec_) {
		thread_handle.join();
	}
}

PoolStatus ThreadPool::Start(){

	for (int i = 1; i < thread_Count_; i++) {
		threads_Vec_.push_back(std::thread(&ThreadPool::Task_Executor, this));
	}
	return current_Pool_Status_;
}

PoolStatus ThreadPool::End(){
	is_not_exit_threads = false;
	// TODO: send events for thread which are waiting for new task. Simply sleeping for temp sollution
	//std::this_thread::sleep_for(std::chrono::milliseconds(thread_Count_*10+10));
	return current_Pool_Status_;
}

bool ThreadPool::Add_Tasks(std::queue<Task> task_list)
{
	try {
		while (!task_list.empty()) {
			task_Q_.push(task_list.front());
			task_list.pop();
		}
	}
	catch (std::exception& e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}

bool ThreadPool::Add_Task(Task& new_task )
{
	try {
		task_Q_.push(new_task);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}

void ThreadPool::Task_Executor(){

	Task task;
	while (is_not_exit_threads) {
		task_locker.lock();
		if (!task_Q_.empty()) {
			task = task_Q_.front();
			task_Q_.pop();
		}
		else {
			task_locker.unlock();
			//TODO: wait for the new task signal. Currently simply using sleep calls
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
			continue;
		}
		task_locker.unlock();

		// process the task. TODO: currently passing nullptr, once usecase found will use it.
		task.call_back((void*)(task.task_name.c_str()));
	}
}
