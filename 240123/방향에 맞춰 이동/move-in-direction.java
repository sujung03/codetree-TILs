import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // 여기에 코드를 작성해주세요.
        Scanner sc = new Scanner(System.in);

        int x = 0;
        int y = 0;

        int t = sc.nextInt();

        for(int i = 0; i < t; i++) {
            char c = sc.next().charAt(0);
            int n = sc.nextInt();

            if (c == 'N') {
                y += n;
            }
            else if (c == 'S') {
                y -= n;
            }
            else if (c == 'E') {
                x += n;
            }
            else if (c == 'W'){
                x -= n;
            }
        }

        System.out.println(x+" "+y);

        sc.close();
    }
}