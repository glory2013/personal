/*
 * =====================================================================================
 *       Filename:  multiThread.cpp
 *        Version:  1.0
 *        Created:  05/12/2013 02:52:48 PM
 *        迅雷笔试题：
 *        编写一个程序，开启3个线程，这3个线程的ID分别为A、B、C，
 *        每个线程将自己的ID在屏幕上打印10遍，要求输出结果必须按ABC的顺序显示；如:ABCABC….依次递推。
 * =====================================================================================
 */

#include <iostream>
#include <stdio.h>
#include <pthread.h>
using namespace std;

int n = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t con[3] = {PTHREAD_COND_INITIALIZER, PTHREAD_COND_INITIALIZER, PTHREAD_COND_INITIALIZER};
char s[4] = "ABC";

void* func(void *v){
    int i = long(v);
    int time = 0;
    pthread_mutex_lock(&mutex);
    while(time < 3){
        while((n % 3) != i){
            cout << "cond_wait:" << s[i] << endl;
            int ret = pthread_cond_wait(&con[i], &mutex);
            cout << "cond_resume:" << s[i] << endl;
        }
        cout << s[long(v)] << endl;
        ++n;
        ++time;
        cout << "cond_signal:" << s[(i+1)%3] << endl;
        pthread_cond_signal(&con[(i+1)%3]);
    }
    pthread_cond_signal(&con[(i+1)%3]);
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main(){
    pthread_t tids[3];
    assert(pthread_create(&tids[1], NULL, func, (void *)1) == 0);
    sleep(1);
    assert(pthread_create(&tids[0], NULL, func, (void *)0) == 0);
    assert(pthread_create(&tids[2], NULL, func, (void *)2) == 0);

    for (int i = 0; i < 3; ++i){
        pthread_join(tids[i], NULL);
        cout << "joined:" << i << endl;
    }
    return 0;
}
