package com.company;

public class ControlPanel {
    public static byte[] point(long menuPoint, int time) {
        System.out.println("\nПункт меню = " + menuPoint);
        System.out.println("Час = " + time + "хв.");
        return new byte[time];
    }
}
