#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void * thread_sum(void *);
int TotalCount=0;
int iNumber;

pthread_mutex_t mVar=PTHREAD_MUTEX_INITIALIZER;

int main()
{
    int iCount,jCount;
    int threadPara;
    int PrimeFlag=1;
    
    pthread_t tid;
    
    printf("Enter Number Up to Which You want to Count Prime Numbers :");
    
    scanf("%d",&iNumber);
    
    threadPara=iNumber/2 + 1;
    
    pthread_create(&tid,NULL,thread_sum,(void *)&threadPara);
    
    for(iCount=2 ; iCount <= iNumber/2; iCount++)
    
    {
    
        for(jCount=2 ; jCount < iCount; jCount++)
        
        {
        
            if(iCount % jCount ==0)
            {
                PrimeFlag=0;
                break;
            }
        }
        
        if(PrimeFlag==1)
        {    
            printf("[ %d ]  Main\n",iCount);
            pthread_mutex_lock(&mVar);
            TotalCount++;
            pthread_mutex_unlock(&mVar);
        }
        
        else
        {
            PrimeFlag=1;
        }
    }
    
    pthread_join(tid,NULL);
    
    printf("Final Count is : %d \n",TotalCount);
    return 0;
}

void *thread_sum(void *no)

{
    int *ifrom, iCount, jCount;
    int PrimeFlag=1;
    ifrom=(int*)no;
    
    for(iCount=*ifrom ; iCount <= iNumber;iCount++)
    {
        for(jCount=2;jCount<iCount; jCount++)
        
        {
            if(iCount%jCount==0)
            
            {
                PrimeFlag=0;
                break;
            }
        }
        
        if(PrimeFlag==1)
        {    
            printf("[ %d ] Thread\n",iCount);
            pthread_mutex_lock(&mVar);
            TotalCount++;
            pthread_mutex_unlock(&mVar);
        }        
        PrimeFlag=1;        
    }
    pthread_exit(NULL);    
}