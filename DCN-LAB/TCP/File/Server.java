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

class Server {
    public static void main(String[] args) {
        try {
            ServerSocket ss = new ServerSocket(9990);
            System.out.println("File Server started...");

            Socket s = ss.accept();
            System.out.println("Client connected");

            DataInputStream din = new DataInputStream(s.getInputStream());

            String fileName = din.readUTF();
            FileOutputStream fos = new FileOutputStream("received_" + fileName);

            byte[] buffer = new byte[4096];
            int bytes;

            while ((bytes = din.read(buffer)) > 0) {
                fos.write(buffer, 0, bytes);
                if (bytes < 4096) break;
            }

            System.out.println("File received successfully");

            fos.close();
            din.close();
            s.close();
            ss.close();

        } catch (Exception e) {
            System.out.println(e);
        }
    }
}