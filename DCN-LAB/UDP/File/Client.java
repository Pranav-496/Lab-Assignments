import java.net.*;
import java.io.*;

public class Client {
    public static void main(String[] args) throws Exception {
        DatagramSocket socket = new DatagramSocket();
        InetAddress address = InetAddress.getByName("localhost");

        String filePath = "sample.mp4"; // Change file here
        File file = new File(filePath);

        // Send file name first
        DatagramPacket fileNamePacket = new DatagramPacket(file.getName().getBytes(), file.getName().length(), address, 5000);
        socket.send(fileNamePacket);

        FileInputStream fis = new FileInputStream(file);
        byte[] buffer = new byte[4096];

        int bytesRead;
 
        while ((bytesRead = fis.read(buffer)) != -1) {
            DatagramPacket packet = new DatagramPacket(buffer, bytesRead, address, 5000);

            socket.send(packet);

            // Wait for ACK
            byte[] ackBuffer = new byte[10];
            DatagramPacket ackPacket = new DatagramPacket(ackBuffer, ackBuffer.length);
            socket.receive(ackPacket);
        }
 
        // Send END signal
        String endMsg = "END";
        DatagramPacket endPacket = new DatagramPacket(endMsg.getBytes(), endMsg.length(), address, 5000);
        socket.send(endPacket);

        fis.close();
        socket.close();

        System.out.println("File sent successfully!");
    }
}