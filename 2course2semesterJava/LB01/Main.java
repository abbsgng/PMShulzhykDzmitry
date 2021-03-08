package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        final String FILENAME = "C:\\Users\\Термокаскад\\Desktop\\JavaProjects\\files\\Strings.txt";

        String strings[] = InputStrings.input(FILENAME);
        String smallest = StringsProcessing .smallest(strings);

        System.out.println("Smallest string: " + smallest);
        System.out.println("Length: " + smallest.length());
    }
}
