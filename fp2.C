#include<stdio.h>
#include<conio.h>
#include<math.h>

void main()
{
  char func_units[][30]={"External Inputs","External Outputs","External Enquiries","Internal Logical Files","External Interface Files"};
  char complexity[3][10]={"Opt","Likely","Pess"};
  int input[5][3],i, weight[5];
  float fp[5],fp_tot=0, estd_count[5], fp_estd=0, rating=0,f=0;
  float lrate, prod, cost_fp, cost_tot, effort;

  clrscr();
  //calculating Estimated count
  printf("\t\t\t\t %s\t%s\t%s",complexity[0],complexity[1],complexity[2]);
  for(i=0;i<5;i++)
  {

    printf("\nEnter no.of %s  : ",func_units[i]);
    scanf("%d\t%d\t%d",&input[i][0], &input[i][1], &input[i][2]);

    estd_count[i]=(float)((input[i][0]+(4*input[i][1])+input[i][2]))/(float)6;
    printf("Estimated count for %d is %6.2f",i+1, estd_count[i]);
  }
  //for calculating FP
  for(i=0; i<5; i++)
  {
    printf("\nEnter the weight for %s\t",func_units[i]);
    scanf("%d", &weight[i]);
    fp[i]=(float)weight[i]* (float)estd_count[i];
    printf("\nFP count for %d is %6.2f", i+1, fp[i]);
    fp_tot=(ceil(fp_tot))+fp[i];
  }
  printf("\nFP total = %6.2f", ceil(fp_tot) );

  printf("\nEnter Rating of 14 Value Adjustment Factors on the scale of 0-5 :-\n");
/*  printf("\n 1 - Backup and recovery");
  printf("\n 1 - Incidental");
  printf("\n 2 - Moderate");
  printf("\n 3 - Average");
  printf("\n 4 - Significant");
  printf("\n 5 - Essential");
  */
  for(i=0;i<14;i++)
  {
    scanf("\t%f",&rating);
    f=f + rating;
  }
  printf("\nSummation Fi is %f",f);

  fp_estd=((ceil(fp_tot))*(0.65+(0.01*f)));
  printf("\nFp estimated = %f", ceil(fp_estd) );

  printf("\nEnter the productivity rate(FP/PM):\t");
  scanf("%f",&prod);

  printf("\nEnter the labour rate(in $):\t");
  scanf("%f",&lrate);
  cost_fp=(lrate/prod);
  cost_tot=(fp_estd * cost_fp);

  printf("\nThe total cost is $%f",ceil(cost_tot));

  effort=(fp_estd / prod);
  printf("\nThe total effort is %f",ceil(effort) );

  getch();
//  return(0);

}