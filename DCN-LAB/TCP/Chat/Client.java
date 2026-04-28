/*
Name: Pranav Shailesh Landge
Class: SY-A
Roll_no: 41
Subject: DCN
Assignment-08-Write a program using TCP socket for wired network for following
a. Say Hello to Each other
b. File transfer
c. Calculator
*/

import java.io.*;
import java.net.*;
import java.util.*;

class Client
{
	public static void main(String args[])
	{
		try
		{
			Socket s = new Socket("localhost", 9989);
			DataInputStream din = new DataInputStream(s.getInputStream());
			DataOutputStream dos = new DataOutputStream(s.getOutputStream());
			Scanner sc = new Scanner(System.in);
			String str_client="", str_server="";
			System.out.println("****************Client**************");
			while(!str_client.equals("stop"))
			{
				str_client=sc.nextLine();
				dos.writeUTF(str_client);
				dos.flush();
				str_server = din.readUTF();
				System.out.println("Server says: " + str_server);
			
			}
			s.close();
			sc.close();
		}
		catch(Exception e) {System.out.println(e); }
	}
}
