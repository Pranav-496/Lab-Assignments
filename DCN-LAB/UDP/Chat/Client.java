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
        InetAddress serverIP = InetAddress.getByName("localhost");
        int port = 9989;

        Scanner sc = new Scanner(System.in);

        System.out.println("UDP Chat Client Started...");

        Thread sender = new Thread(() -> {
            try {
                while (true) {
                    String msg = sc.nextLine();

                    DatagramPacket dp = new DatagramPacket(
                            msg.getBytes(),
                            msg.length(),
                            serverIP,
                            port
                    );
                    ds.send(dp);

                    if (msg.equals("stop")) break;
                }
            } catch (Exception e) {}
        });

        Thread receiver = new Thread(() -> {
            try {
                while (true) {
                    byte[] buffer = new byte[1024];
                    DatagramPacket dp = new DatagramPacket(buffer, buffer.length);
                    ds.receive(dp);

                    String msg = new String(dp.getData(), 0, dp.getLength());
                    System.out.println("Server: " + msg);

                    if (msg.equals("stop")) break;
                }
            } catch (Exception e) {}
        });

        sender.start();
        receiver.start();

        sender.join();
        receiver.join();

        ds.close();
        sc.close();
    }
}