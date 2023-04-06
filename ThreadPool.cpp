#include "ThreadPool.h"

ThreadPool::ThreadPool(int threadCount):thread_Count_(threadCount), 
										current_Pool_Status_(IDLE){
}

PoolStatus ThreadPool::Start(){
	return current_Pool_Status_;
}

PoolStatus ThreadPool::End(){
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
