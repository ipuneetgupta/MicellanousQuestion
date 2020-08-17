import java.util.*;

public class Main
{
    public static void ans(int a, int b){
        if(a == b){
            System.out.print("Coalition government ");
        }else if(a > b){
            System.out.print("A ");
        }else{
            System.out.print("B ");
        }
    }
    
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int size = s.nextInt();
		String str = s.next();
		
		int acount = 0, bcount = 0;
		int i = 0, alast = -1, blast = -1;
		Character last = null;
		
		for(; i < str.length(); i++){
		    Character cc = str.charAt(i);
		    if(cc.equals('A')){
		        alast = i;
		        last = 'A';
		        acount += (i + 1);
		        break;
		    }else{
		        last = 'B';
		        blast = i;
		        bcount += 1;
		        break;
		    }
		}
		
		if(i == str.length()){
		    ans(acount, bcount);
		    return;
		}
		
		i += 1;
		for(; i < str.length(); i++){
		    Character cc = str.charAt(i);
		    
		    if(cc.equals('A')){
		        if(last.equals('A')){
		            acount += (i - alast - 1);
		        }else{
                    int gap = (i - blast - 1);
                    acount += (gap / 2);
                    bcount += (gap / 2);
		        }
		        acount += 1;
		        alast = i;
		        
		    }else if(cc.equals('B')){
		        if(last.equals('B')){
		            bcount += (i - blast - 1);
		        }
		        bcount += 1;
		        blast = i;
		    }
		}
		
		if(last.equals('B')){
		    bcount += (str.length() - blast - 1);
		}
		System.out.println(acount +" " + bcount);
		ans(acount, bcount);
	}
}