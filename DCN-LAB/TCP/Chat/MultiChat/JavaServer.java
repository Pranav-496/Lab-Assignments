
import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.*;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;
public class JavaServer
{
    static int clientcount;
    public static void main(String [] args) 
    {
         clientcount=0;
     
try{  
ServerSocket ss=new ServerSocket(8000);
       while(true)
       {
          
           Socket s=ss.accept();
           System.out.println("New Client connected");
           clientcount++;
          Thread t1=new Thread(new Connect(s,clientcount));     // 
          t1.start();
       }
     }catch(Exception e){

}
        
    }//main
    
}//class1
class Connect implements Runnable
{
                                                                                          //// everything about s
        Socket s;
        int id;
   public Connect(Socket s,int id) {
        this.s=s;
        this.id=id;   }
        
    @Override
    public void run() {
try{        

                DataInputStream din=new DataInputStream(s.getInputStream());  
		DataOutputStream dout=new DataOutputStream(s.getOutputStream());  
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));  
		  
		String str="",str2="";  
		
            
                while(!str.equals("stop")){  
			str=din.readUTF();  
			System.out.println("client "+id+":"+str);  
			str2=br.readLine();  
			dout.writeUTF(str2);  
			dout.flush();  
		}  
		din.close();  
		s.close();  
            
              

}catch(Exception e){

}
    
    
    }
}
