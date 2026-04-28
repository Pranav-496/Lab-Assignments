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

class Client {
    public static void main(String[] args) {
        try {
            Socket s = new Socket("localhost", 9990);

            DataOutputStream dos = new DataOutputStream(s.getOutputStream());

            String filePath = "./test.txt";
            File file = new File(filePath);

            FileInputStream fis = new FileInputStream(file);

            dos.writeUTF(file.getName());

            byte[] buffer = new byte[4096];
            int bytes;

            while ((bytes = fis.read(buffer)) > 0) {
                dos.write(buffer, 0, bytes);
            }

            System.out.println("File sent successfully");

            fis.close();
            dos.close();
            s.close();

        } catch (Exception e) {
            System.out.println(e);
        }
    }
}