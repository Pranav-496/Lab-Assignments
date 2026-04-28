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

class Server {

    static class ClientInfo {
        InetAddress address;
        int port;
    }

    public static void main(String[] args) throws Exception {

        DatagramSocket ds = new DatagramSocket(9989);
        ClientInfo client = new ClientInfo();
        Scanner sc = new Scanner(System.in);

        System.out.println("UDP Chat Server Started...");

        Thread receiver = new Thread(() -> {
            try {
                while (true) {
                    byte[] buffer = new byte[1024];
                    DatagramPacket dp = new DatagramPacket(buffer, buffer.length);
                    ds.receive(dp);

                    String msg = new String(dp.getData(), 0, dp.getLength());
                    System.out.println("Client: " + msg);

                    client.address = dp.getAddress();
                    client.port = dp.getPort();

                    if (msg.equals("stop")) break;
                }
            } catch (Exception e) {}
        });

        Thread sender = new Thread(() -> {
            try {
                while (true) {
                    String msg = sc.nextLine();

                    if (client.address != null) {
                        DatagramPacket dp = new DatagramPacket(
                                msg.getBytes(),
                                msg.length(),
                                client.address,
                                client.port
                        );
                        ds.send(dp);
                    }

                    if (msg.equals("stop")) break;
                }
            } catch (Exception e) {}
        });

        receiver.start();
        sender.start();

        receiver.join();
        sender.join();

        ds.close();
        sc.close();
    }
}