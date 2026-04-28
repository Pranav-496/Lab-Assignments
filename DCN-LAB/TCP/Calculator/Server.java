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
            ServerSocket ss = new ServerSocket(9991);
            System.out.println("Calculator Server started...");

            Socket s = ss.accept();

            DataInputStream din = new DataInputStream(s.getInputStream());
            DataOutputStream dos = new DataOutputStream(s.getOutputStream());

            while (true) {
                String expr = din.readUTF();

                if (expr.equals("exit")) break;

                String[] parts = expr.split(" ");
                int a = Integer.parseInt(parts[0]);
                int b = Integer.parseInt(parts[2]);
                String op = parts[1];

                int result = 0;

                if (op.equals("+")) result = a + b;
                else if (op.equals("-")) result = a - b;
                else if (op.equals("*")) result = a * b;
                else if (op.equals("/")) result = a / b;

                dos.writeUTF("Result: " + result);
                dos.flush();
            }

            s.close();
            ss.close();

        } catch (Exception e) {
            System.out.println(e);
        }
    }
}