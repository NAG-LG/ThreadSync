#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <thread>
#include <iostream>
#include <string>
#include <mutex>
#include <vector>
#include <string>
#include <queue>
#include <chrono>
using namespace std;

enum PoolStatus {
	IDLE,
	RUNNING,
	FAILED
};

struct Task {
	std::string task_name;
	void* (*call_back)(void*);
};

class ThreadPool {
public:
	ThreadPool(int threadCount);
	~ThreadPool();
	PoolStatus Start();
	PoolStatus End();
	bool Add_Tasks(std::queue<Task> );
	bool Add_Task(Task& new_task);
	void Task_Executor();
private:
	int thread_Count_;
	std::atomic<bool> is_not_exit_threads;
	std::vector<std::thread> threads_Vec_;
	PoolStatus current_Pool_Status_;
	std::queue<Task> task_Q_;
	std::mutex task_locker;
};

#endif // !THREAD_POOL_H