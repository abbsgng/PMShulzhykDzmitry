package com.company.LB04;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class WorkWithText {
    public static int countWords(final String filename) {
        int count = 0;
        String buffer = new String();
        try {
            Scanner scanner = new Scanner(new File(filename));
            while (scanner.hasNextLine()) {
                buffer = scanner.nextLine();
                count++;
            }
            return count;
        } catch (FileNotFoundException e) {
            System.err.println("File not found");
        }
        return count;
    }

    public static String[][] getWords(final String filename) {
        int length = countWords(filename);
        String[][] words=new String[length][];
        try {
            Scanner scanner = new Scanner(new File(filename));
            int i = 0;
            while (scanner.hasNextLine()) {
                words[i]= scanner.nextLine().split(" ");
                ++i;
            }
            return words;
        } catch (FileNotFoundException e) {
            System.err.println("File not found");
        }
        return words;
    }
    public static int countOfWords(String[][] source) {
        int count = 0;
        for (int i = 0; i < source.length; ++i) {
            for (int j = 0; j < source[i].length; ++j) {
                ++count;
            }
        }
        return count;
    }

    public static String[] wordsToArray(String[][] words) {
        String[] source = new String[countOfWords(words)];
        for (int i = 0, k = 0; i < words.length; ++i) {
            for (int j = 0; j < words[i].length; ++j, ++k) {
                source[k] = words[i][j].trim();
            }
        }
        return source;
    }
}
