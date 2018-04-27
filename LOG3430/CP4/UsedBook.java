import java.util.*;

class UsedBook extends Book{
    int status ;
    int year ;
    public int getStatus(){
        return status;
    }
     public void setStatus(int n){
        status=n;
    }
      public int getYear(){
        return year;
    }
     public void setYear(int n){
        year=n;
     }
    public void addUsedCopy(String t, String a, int np, int s, int  y){
	title=t;
	author=a;
	pages=np;
	status=s;
	year=y;
    }
    public void changePrice(double p){
	setPrice(p);

    }
    public void  giftBook(){
	price=0.0;

    }
    public void showStatus(){
	if (status == 0)
	    System.out.println("Like new\n");
	else if (status == 1)
	    System.out.println("Good condition\n");
	else if (status == 2)
	    System.out.println("Used\n");
	else
	    System.out.println("Damaged copy\n");
	    
    }
    
}
