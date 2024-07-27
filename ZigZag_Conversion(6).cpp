class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1)
            return s; // Tek satır olduğunda, orijinal dizeyi döndür

        char[][] zigZag = new char[numRows][s.length()];
        int i = 0, j = 0;
        boolean goingDown = false;

        for (int k = 0; k < s.length(); k++) {
            zigZag[i][j] = s.charAt(k); // Karakteri matrisin (i, j) konumuna yerleştir

            // Yön değişimi için çapraz hareket
            if (i == 0 || i == numRows - 1) {
                goingDown = !goingDown;
                j++;
            }

            // Yönü takip ederek satır ve sütun indeksini güncelle
            i += goingDown ? 1 : -1;
            if (i != 0 && !goingDown) {
                j++; // Yön yukarıdan aşağıya değiştiğinde sütun indeksini artır
            }
        }

        // Sonuç dizesini oluştur
        StringBuilder solution = new StringBuilder();
        for (i = 0; i < numRows; i++) {
            for (j = 0; j < s.length(); j++) {
                if (zigZag[i][j] != '\0') { // Boş karakterleri kontrol et
                    solution.append(zigZag[i][j]);
                }
            }
        }

        return solution.toString();
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        String s = "PAYPALISHIRING";
        int numRows = 3;
        System.out.println(solution.convert(s, numRows)); // Beklenen çıktı: PAHNAPLSIIGYIR
    }
}
