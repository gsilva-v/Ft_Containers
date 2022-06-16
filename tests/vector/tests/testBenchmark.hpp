#pragma once
#include "../../../include/vector.hpp"
#include <vector>
#include <iostream>
#include <sstream>
#include <ctime>
#include <sys/time.h>
#include <sstream>

class testBenchmark
{
private:

public:
	testBenchmark();
	static void	testTime(){
		std::cout <<"Testing: Inserting at back, iterating and pop this" << std::endl;
		{
			struct timeval time_now;   
			gettimeofday(&time_now, NULL);   
			time_t start = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
			std::stringstream buf;
			std::vector<int> stdv;
			for (int i = 1; i < 1000000 ; i++){
				stdv.push_back(i);
			}

			while (!stdv.empty()){
				buf << stdv.back();
				stdv.pop_back();
			}
			
			gettimeofday(&time_now, NULL);   
			time_t finish = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
			std::cout <<"std: "<<  finish - start << " ms" << std::endl;
		}
		{
			struct timeval time_now;   
			gettimeofday(&time_now, NULL);   
			time_t start = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
			std::stringstream buf;
			ft::vector<int> stdv;
			for (int i = 1; i < 1000000 ; i++){
				stdv.push_back(i);
			}

			while (!stdv.empty()){
				buf << stdv.back();
				stdv.pop_back();
			}
			
			gettimeofday(&time_now, NULL);   
			time_t finish = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
			std::cout <<"ft: "<<  finish - start << " ms" << std::endl;
		}
	}

	static void	testTime2(){
		std::cout <<"\nTesting: Inserting at back and clear all" << std::endl;
		{
			struct timeval time_now;   
			gettimeofday(&time_now, NULL);   
			time_t start = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
			std::stringstream buf;
			std::vector<int> stdv;
			for (int i = 1; i < 1000000 ; i++){
				stdv.push_back(i);
			}

			
			stdv.clear();
			
			gettimeofday(&time_now, NULL);   
			time_t finish = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
			std::cout <<"std: "<<  finish - start << " ms" << std::endl;
		}
		{
			struct timeval time_now;   
			gettimeofday(&time_now, NULL);   
			time_t start = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
			std::stringstream buf;
			ft::vector<int> stdv;
			for (int i = 1; i < 1000000 ; i++){
				stdv.push_back(i);
			}

			stdv.clear();
			
			gettimeofday(&time_now, NULL);   
			time_t finish = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
			std::cout <<"ft: "<<  finish - start << " ms" << std::endl;
		}
	}
	static void	testTime3(){
		std::cout <<"\nTesting: Inserting at back and iteraring" << std::endl;
		{
			struct timeval time_now;   
			gettimeofday(&time_now, NULL);   
			time_t start = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
			std::stringstream buf;
			std::vector<int> stdv;
			for (int i = 1; i < 1000000 ; i++){
				stdv.push_back(i);
			}

			for (std::vector<int>::iterator it = stdv.begin(); it != stdv.end(); it++)
				buf << *it;

			gettimeofday(&time_now, NULL);   
			time_t finish = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
			std::cout <<"std: "<<  finish - start << " ms" << std::endl;
		}
		{
			struct timeval time_now;   
			gettimeofday(&time_now, NULL);   
			time_t start = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
			
			std::stringstream buf;
			ft::vector<int> stdv;
			for (int i = 1; i < 1000000 ; i++){
				stdv.push_back(i);
			}

			for (ft::vector<int>::iterator it = stdv.begin(); it != stdv.end(); it++)
				buf << *it;
			
			gettimeofday(&time_now, NULL);   
			time_t finish = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
			std::cout <<"ft: "<<  finish - start << " ms" << std::endl;
		}
	}

	static void	testTime4(){
		std::cout <<"\nTesting: Creating new vector with operator =" << std::endl;
		{
			struct timeval time_now;   
			gettimeofday(&time_now, NULL);   
			time_t start = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
			std::stringstream buf;
			std::vector<int> stdv;
			std::vector<int> stdv2;
			for (int i = 1; i < 1000000 ; i++){
				stdv.push_back(i);
			}

			stdv2 = stdv;
			for (std::vector<int>::iterator it = stdv2.begin(); it != stdv2.end(); it++)
				buf << *it;

			gettimeofday(&time_now, NULL);   
			time_t finish = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
			std::cout <<"std: "<<  finish - start << " ms" << std::endl;
		}
		{
			struct timeval time_now;   
			gettimeofday(&time_now, NULL);   
			time_t start = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
			std::stringstream buf;
			ft::vector<int> stdv;
			ft::vector<int> stdv2;
			for (int i = 1; i < 1000000 ; i++){
				stdv.push_back(i);
			}

			stdv2 = stdv;
			for (ft::vector<int>::iterator it = stdv2.begin(); it != stdv2.end(); it++)
				buf << *it;
			
			gettimeofday(&time_now, NULL);   
			time_t finish = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
			std::cout <<"ft: "<<  finish - start << " ms" << std::endl;
		}
	}
	
	static void	testTime5(){
		std::cout <<"\nTesting: Inserting with insert(vector.begin(), value)" << std::endl;
		{
			struct timeval time_now;   
			gettimeofday(&time_now, NULL);   
			time_t start = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
			std::stringstream buf;
			std::vector<int> stdv;
			for (int i = 1; i < 10000 ; i++){
				stdv.insert(stdv.begin(), i);
			}

			for (std::vector<int>::iterator it = stdv.begin(); it != stdv.end(); it++)
				buf << *it;

			gettimeofday(&time_now, NULL);   
			time_t finish = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
			std::cout <<"std: "<<  finish - start << " ms" << std::endl;
		}
		{
			struct timeval time_now;   
			gettimeofday(&time_now, NULL);   
			time_t start = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
			std::stringstream buf;
			ft::vector<int> stdv;
			for (int i = 1; i < 10000 ; i++){
				stdv.insert(stdv.begin(), i);
			}

			for (ft::vector<int>::iterator it = stdv.begin(); it != stdv.end(); it++)
				buf << *it;
			
			gettimeofday(&time_now, NULL);   
			time_t finish = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
			std::cout <<"ft: "<<  finish - start << " ms" << std::endl;
		}
	}

	~testBenchmark();
};


