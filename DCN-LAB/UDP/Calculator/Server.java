/*
Name: Pranav Shailesh Landge
Class: SY-A
Roll_no: 41
Subject: DCN
Assignment-09-Write a program using UDP Sockets to enable file transfer (Script, Text,
Audio and Video one file each) between two machines.
*/

import java.net.*;

class Server {
    public static void main(String[] args) throws Exception {
        DatagramSocket ds = new DatagramSocket(9991);
        byte[] buffer = new byte[1024];

        System.out.println("UDP Calculator Server started...");

        while (true) {
            DatagramPacket dp = new DatagramPacket(buffer, buffer.length);
            ds.receive(dp);

            String expr = new String(dp.getData(), 0, dp.getLength());
            if (expr.equals("exit")) break;

            String[] parts = expr.split(" ");
            int a = Integer.parseInt(parts[0]);
            int b = Integer.parseInt(parts[2]);
            String op = parts[1];

            int res = 0;
            if (op.equals("+")) res = a + b;
            else if (op.equals("-")) res = a - b;
            else if (op.equals("*")) res = a * b;
            else if (op.equals("/")) res = a / b;

            String reply = "Result: " + res;

            DatagramPacket dpSend = new DatagramPacket(
                reply.getBytes(),
                reply.length(),
                dp.getAddress(),
                dp.getPort()
            );
            ds.send(dpSend);
        }

        ds.close();
    }
}