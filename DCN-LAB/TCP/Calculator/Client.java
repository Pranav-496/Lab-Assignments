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

class Client {
    public static void main(String[] args) {
        try {
            Socket s = new Socket("localhost", 9991);

            DataInputStream din = new DataInputStream(s.getInputStream());
            DataOutputStream dos = new DataOutputStream(s.getOutputStream());
            Scanner sc = new Scanner(System.in);

            System.out.println("Enter expression (e.g., 5 + 3) or 'exit'");

            while (true) {
                String input = sc.nextLine();
                dos.writeUTF(input);
                dos.flush();

                if (input.equals("exit")) break;

                String result = din.readUTF();
                System.out.println(result);
            }

            s.close();
            sc.close();

        } catch (Exception e) {
            System.out.println(e);
        }
    }
}