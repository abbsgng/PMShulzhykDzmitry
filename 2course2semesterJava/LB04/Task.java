package com.company.LB04;

import java.util.Arrays;

public class Task {
    public static String[] searchWords(String[] strings) {
        int countOfNull = 0;
        for (int i = 0; i < strings.length; ++i) {
            if (strings[i].isEmpty()) {
                strings[i] = null;
                ++countOfNull;
                continue;
            }
            if (strings[i].length() < 2) {
                continue;
            }
            if (strings[i].charAt(0) != strings[i].charAt(strings[i].length() - 1)) {
                strings[i] = null;
                ++countOfNull;
            }
        }
        String newStrings[] = new String[strings.length - countOfNull];
        for (int i = 0, j = 0; i < strings.length; ++i) {
            if (strings[i] != null) {
                newStrings[j] = strings[i];
                ++j;
            }
        }
        return newStrings;
    }

    public static String[] deleteReplay(String[] strings) {
        Arrays.sort(strings);
        if (strings.length == 1) return strings;
        if (strings.length == 0) return new String[]{};

        int unique = 1;
        for (int i = 1; i < strings.length; i++) {
            if (!strings[i].equals(strings[i-1])) {
                unique++;
            }
        }
        String[] result = new String[unique];
        int k = 0;
        if (result.length > 0) {
            result[k++] = strings[0];
        }
        for (int i = 1; i < strings.length; i++) {
            if (!strings[i].equals(strings[i-1])) {
                result[k++] = strings[i];
            }
        }
        return result;
    }
}

