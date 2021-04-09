package com.company.LB04;

public class Main {
    public static void main(String[] args) {
        final String FILENAME = "C:\\Users\\Термокаскад\\JAVA_LB\\src\\com\\company\\LB04\\text.txt";
        String [][] words=WorkWithText.getWords(FILENAME);
        String[] strings=WorkWithText.wordsToArray(words);
        String[] task=Task.searchWords(strings);
        task=Task.deleteReplay(task);
        for (String element:task) {
            System.out.println(element);
        }
    }
}
