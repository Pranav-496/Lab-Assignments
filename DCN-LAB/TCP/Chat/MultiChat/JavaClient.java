
//To execute on two machines write ip address of server in the //code of client then compile n execute
import java.net.*;
import java.io.*;  

public class JavaClient {

	public static void main(String args[]) throws Exception{  
		Socket s=new Socket("LocalHost",8000);  
		DataInputStream din=new DataInputStream(s.getInputStream());  
		DataOutputStream dout=new DataOutputStream(s.getOutputStream());  
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));  
		  
		String str="",str2="";  
             
		while(!str.equals("stop")){  
			str=br.readLine();  
                          if(str.equals("stop"))
                            break;
			dout.writeUTF(str);  

			dout.flush();  
			
                  str2=din.readUTF();  
               
			System.out.println("Server says: "+str2);  
		}  
                
		dout.close();  
		s.close();  
                
                
                }
}
