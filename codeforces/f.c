#include <stdio.h>
   int main()
   {
       float amnt;
       int wthdrw;
       float remain;
       scanf("%d %f", &wthdrw, &amnt);
       if (wthdrw % 5 == 0 && wthdrw > 0 && wthdrw <= 2000 && amnt >=0 && amnt <= 2000)
       {
          if (amnt > (wthdrw + 0.5))
         {
              remain = amnt - wthdrw - 0.5;                                                                                                         
          }
          else
          {
              remain = amnt;
          }
      }
      else
      {
              remain =amnt;
      }
      printf("%.2f\n", remain);
  
          // your code goes here
          return 0;
  }



