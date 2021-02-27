package com.company;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class InputStrings {

    public static String[] input(String filename) {
        try {
            Scanner scanner = new Scanner(new File(filename));
            int length = scanner.nextInt();
            if(length<1)
            {
                throw new IllegalArgumentException();
            }
            String strings[] = new String[length];
            int i = 0;
            while (i<length && scanner.hasNextLine()) {
                strings[i] = scanner.nextLine();
                ++i;
            }
            return strings;
        } catch (FileNotFoundException e) {
            System.err.println("File not found");
        }
        return null;
    }
}
