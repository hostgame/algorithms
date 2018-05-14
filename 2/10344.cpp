#include <iostream>

using namespace std;

int num[5];
int flag;
int vis[5];
    
    
void dfs(int numOfElements, int sum)
{
    
  int i;
  if(sum == 23 && numOfElements ==5)
  {
       flag = 1 ;  return ;
  }
  else{
    for(i = 0 ; i < 5 ; i++){
       if(!vis[i]){
           vis[i] = 1 ;
           dfs(numOfElements + 1, sum + num[i]) ;
           dfs(numOfElements + 1, sum * num[i] ) ;
           dfs(numOfElements + 1, sum - num[i] ) ;
           vis[i] = 0 ;
       }
    }
 }

}
int main()
{
     while(cin >> num[0] >> num[1] >> num[2] >> num[3] >> num[4])
     {

         if(num[0] == 0 and num[1] == 0 and num[2] == 0 and num[3] == 0 and num[4] == 0)
             return 0;
         
         flag = 0 ;
         for(int i = 0; i < 5; i++)
         {
             vis[i] = 1;
             dfs(1, num[i]) ;
             vis[i] = 0;
         }
         
         if(flag)
            printf("Possible\n");
         else  printf("Impossible\n");
    }

}