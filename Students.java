import java.io.*;
 
 public class Students{
public static void main(String arg[])throws IOException{
	double user[]=new double[20];
	int st_pt[]=new int[20];
	int i,j,n,s=0,v,sum=0,pre=0,count=1,m,days,pd;
	DataInputStream ob=new DataInputStream(System.in);
	System.out.print("Enter the number of total user stories:");
	n=Integer.parseInt(ob.readLine());
	for(i=0;i<n;i++){
		System.out.print("User story:");
		user[i]=Float.parseFloat(ob.readLine());
		System.out.print("Story point:");
		st_pt[i]=Integer.parseInt(ob.readLine());
	}
	System.out.println("Enter the iteration length in weeks:");
	m=Integer.parseInt(ob.readLine());
	System.out.println("Enter the team's velocity:");
	v=Integer.parseInt(ob.readLine());
	for(i=0;i<=n;i++){
		if(i<n&&sum<v){
			sum+=st_pt[i];
		}
		else if(sum==v){
			System.out.print("Iteration"+count+":");
			for(j=s;j<i;j++)
				System.out.printf("%.1f\t",user[j]);
			System.out.println();
			count++;
			pre=sum;
			sum=st_pt[i];	
			s=i;
		}
		else{
			if(pre>v/2||i==n){
				System.out.print("Iteration"+count+":");
				for(j=s;j<i-1;j++)
					System.out.printf("%.1f\t",user[j]);
				System.out.println();		
				count++;
				pre=sum;
				sum=st_pt[i-1]+st_pt[i];	
				s=i-1;
			}
		}
	}
	count--;
	days=count*6*m;
	System.out.println("The total days:"+days);
pd=(12*8)+(2*8);
System.out.println("Project Duration: " +pd);

}
}

	
			
		
	
