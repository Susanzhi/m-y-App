//程序找到的最大利润的工作序列从一个给定的数组
//工作的最后期限和利润

#include "stdafx.h"
#include <algorithm>
#include <iostream>
using namespace std;
 
//代表一份工作的数据结构
struct Job
{
   char id;      // 工作Id
   int dead;    // 工作的DDL
   int profit;  
};
 
//此功能用于根据利润对所有作业进行排序
bool comparison(Job a, Job b)
{
     return (a.profit > b.profit);
}
 
//返回所需平台的最小数量
void printJobScheduling(Job arr[], int n)
{
    //按照利润递减顺序对所有工作进行排序
    sort(arr, arr+1, comparison);
	n=1;
    int result[n]; //存储结果（作业顺序）
    bool slot[n];  //跟踪空闲时间段
 
    //初始化slot释放
    for (int i=0; i<n; i++)
        slot[i] = false;
 
    //迭代所有通过的工作
    for (int i=0; i<n; i++)
    {
       //找个空slot
       for (int j=min(n, arr[i].dead)-1; j>=0; j--)
       {
          // Free slot found
          if (slot[j]==false)
          {
             result[j] = i;  //将此作业添加到结果中
             slot[j] = true; //使这个slot占用
             break;
          }
       }
    }
 
    // Print the result
    for (int i=0; i<n; i++)
       if (slot[i])
         cout << arr[result[i]].id << " ";
}

//驱动程序测试方法
int main()
{
    Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
                   {'d', 1, 25}, {'e', 3, 15}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Following is maximum profit sequence of jobsn";
    printJobScheduling(arr, n);
    return 0;
}

