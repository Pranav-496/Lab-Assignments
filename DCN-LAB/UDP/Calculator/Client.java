/*
Name: Pranav Shailesh Landge
Class: SY-A
Roll_no: 41
Subject: DCN
Assignment-09-Write a program using UDP Sockets to enable file transfer (Script, Text,
Audio and Video one file each) between two machines.
*/

import java.net.*;
import java.util.*;

class Client {
    public static void main(String[] args) throws Exception {
        DatagramSocket ds = new DatagramSocket();
        ds.setSoTimeout(3000);

        InetAddress ip = InetAddress.getByName("localhost");
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter expression (e.g., 5 + 3) or 'exit'");

        while (true) {
            String input = sc.nextLine();

            if (!input.equals("exit") && !input.matches("\\d+\\s[+\\-*/]\\s\\d+")) {
                System.out.println("Invalid format. Use: number operator number");
                continue;
            }

            DatagramPacket dp = new DatagramPacket(
                input.getBytes(),
                input.length(),
                ip,
                9991
            );
            ds.send(dp);

            if (input.equals("exit")) break;

            try {
                byte[] buffer = new byte[1024];
                DatagramPacket dpRecv = new DatagramPacket(buffer, buffer.length);
                ds.receive(dpRecv);

                String result = new String(dpRecv.getData(), 0, dpRecv.getLength());
                System.out.println(result);
            } catch (SocketTimeoutException e) {
                System.out.println("No response from server (packet lost or server down)");
            }
        }

        ds.close();
        sc.close();
    }
}