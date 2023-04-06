#pragma once
#include <thread>
#include <iostream>
#include <string>
#include <mutex>
#include <vector>
#include <string>
#include <queue>
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
	PoolStatus Start();
	PoolStatus End();
	bool Add_Tasks(std::queue<Task> );
private:
	int thread_Count_;
	std::vector<std::thread> threads_Vec_;
	PoolStatus current_Pool_Status_;
	std::queue<Task> task_Q_;
};