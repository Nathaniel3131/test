package com.company;


// Класс нагріваючого елементу
public class HeatingElement {

    public void start() {

            System.out.println("\nЗапуск мікрохвильовки");
    }

    public void setRotate(long rotate) {
            System.out.println("--------------------------------------------------");
            System.out.println("Прокрутка направляючого ролику");
    }

    public void heatingEnd() {
            System.out.println("--------------------------------------------------");
            System.out.println("Кінець розігрівання іжі!");
    }
}
