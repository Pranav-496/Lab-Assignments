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
class Server
{
	public static void main(String args[]) throws Exception
	{

		ServerSocket ss=new ServerSocket(9989);
		System.out.println("****************Server**************");
		while(true)
		{
			Socket s = ss.accept();
			System.out.println("Client connected!");
			Thread t=new Thread()
			{
				public void run() 
				{
					try
					{
						DataInputStream din = new DataInputStream(s.getInputStream());
						DataOutputStream dos = new DataOutputStream(s.getOutputStream());
						Scanner sc = new Scanner(System.in);
						String str_client="", str_server="";

						while(!str_client.equals("stop"))
						{
							str_client = din.readUTF();
							System.out.println("Client says: " + str_client);
							str_server=sc.nextLine();
							dos.writeUTF(str_server);
							dos.flush();
						}
						s.close();
						ss.close();
						sc.close();
					}
					catch(Exception e){}
				}
			};
		
			t.start();
		}
	}
}
