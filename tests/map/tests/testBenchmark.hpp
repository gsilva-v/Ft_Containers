#pragma once
#include "../../../include/map.hpp"
#include <map>
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
		std::cout <<"Testing: Inserting with operator [] and iterating" << std::endl;
		{
			struct timeval time_now;   
			gettimeofday(&time_now, NULL);   
			time_t start = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
			std::stringstream buf;
			std::map<int, int> stdv;
			
			for (int i = 1; i < 100000; i++){
				stdv[i] = i * 3;
			}

			for (std::map<int, int>::iterator it = stdv.begin(); it != stdv.end(); it++){
				buf << it->first << it->second;
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
			ft::map<int, int> stdv;
			
			for (int i = 1; i < 100000; i++){
				stdv[i] = i * 3;
			}

			for (ft::map<int, int>::iterator it = stdv.begin(); it != stdv.end(); it++){
				buf << it->first << it->second;
			}

			gettimeofday(&time_now, NULL);   
			time_t finish = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
			std::cout <<"ft: "<<  finish - start << " ms" << std::endl;
		}
		
	}
	static void	testTime2(){
		std::cout <<"Testing: Inserting with insert and iterating" << std::endl;
		{
			struct timeval time_now;   
			gettimeofday(&time_now, NULL);   
			time_t start = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
			std::stringstream buf;
			std::map<int, int> stdv;
			
			for (int i = 1; i < 100000; i++){
				stdv.insert(std::make_pair(i, i * 3));
			}

			for (std::map<int, int>::iterator it = stdv.begin(); it != stdv.end(); it++){
				buf << it->first << it->second;
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
			ft::map<int, int> stdv;
			
			for (int i = 1; i < 100000; i++){
				stdv.insert(ft::make_pair(i, i * 3));
			}
			
			for (ft::map<int, int>::iterator it = stdv.begin(); it != stdv.end(); it++){
				buf << it->first << it->second;
			}

			gettimeofday(&time_now, NULL);   
			time_t finish = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
			std::cout <<"ft: "<<  finish - start << " ms" << std::endl;
		}
		
	}

	static void	testTime3(){
		std::cout <<"Testing: Inserting and clear" << std::endl;
		{
			struct timeval time_now;   
			gettimeofday(&time_now, NULL);   
			time_t start = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
			std::stringstream buf;
			std::map<int, int> stdv;
			
			for (int i = 1; i < 100000; i++){
				stdv[i] = i * 3;
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
			ft::map<int, int> stdv;
			
			for (int i = 1; i < 100000; i++){
				stdv[i] = i * 3;
			}
			
			stdv.clear();
			gettimeofday(&time_now, NULL);   
			time_t finish = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
			std::cout <<"ft: "<<  finish - start << " ms" << std::endl;
		}
		
	}

	~testBenchmark();
};


