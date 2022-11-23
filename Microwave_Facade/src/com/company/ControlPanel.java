package com.company;


//  Класс управляючої панелі
public class ControlPanel {
    public static byte[] point(long menuPoint, int time) {
        System.out.println("--------------------------------------------------");
        System.out.println("Вибір пункту меню = " + menuPoint + " - Розігрівання іжі");
        System.out.println("Час розігріву = " + time + "хв.");
        return new byte[time];
    }
}
