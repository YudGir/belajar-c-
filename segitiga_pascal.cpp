#include <iostream>

using namespace std;

int main() {
    int n = 5;

    // for (int i = 1; i <= n; i++) {
    //     cout << endl;

    //     for (int j = 0; j <= n - i; j++) {
    //         cout << i;
    //     }

    // }

    //#1: THE PROGRAM ABOVE RESULTS THIS ( TOOK TIME: 10 MINs )

    //1 1 1 1 1     (i = 1)
    //_ _ _ _ _
    //0 1 2 3 4                  -> j = 4

    //2 2 2 2       (i = 2)
    //_ _ _ _ _
    //0 1 2 3 x                  -> j = 3

    //3 3 3         (i = 3)
    //_ _ _ _ _
    //0 1 2 x x                  -> j = 2

    //4 4           (i = 4)
    //_ _ _ _ _ 
    //0 1 x x x                  -> j = 1

    //5             (i = 5)
    //_ _ _ _ _ 
    //0 x x x x                  -> j = 0


    //==================================================================


    // for (int i = 1; i <= n; i++) {
    //     cout << endl;

    //     for (int k = n; k >= i; k--) {
    //         cout << k;
    //     }
    // }

    //#2: THE PROGRAM ABOVE RESULTS THIS ( TOOK TIME: 15 MINs )
    //5 4 3 2 1       (when, i = 1)
    //_ _ _ _ _
    //0 1 2 3 4                     -> k = 4

    //5 4 3 2         (when, i = 2)
    //_ _ _ _ _
    //0 1 2 3 x                     -> k = 3

    //5 4 3           (when, i = 3)
    //_ _ _ _ _
    //0 1 2 x x                     -> k = 2

    //5 4             (when, i = 4)
    //_ _ _ _ _
    //0 1 x x x                     -> k = 1

    //5               (when, i = 5)
    //_ _ _ _ _
    //0 x x x x                     -> k = 0


    //==================================================================v


    // for (int i = n; i >= 1; i--) {
    //     cout << endl;

    //     for (int k = 1; k <= i; k++) {
    //         cout << k;
    //     }
    // }

    //#3: THE PROGRAM ABOVE RESULTS THIS ( TOOK TIME: 20 MINs )
    //1 2 3 4 5         (thus, j = n - 0 = 5 elements: [1, 2, 3, 4, 5])
    //_ _ _ _ _
    //0 1 2 3 4     -> when, i = 0

    //1 2 3 4           (thus, j = n - 1 = 4 elements: [1, 2, 3, 4])
    //_ _ _ _ _
    //0 1 2 3 x     -> when, i = 1

    //1 2 3             (thus, j = n - 2 = 3 elements: [1, 2, 3])
    //_ _ _ _ _
    //0 1 2 x x     -> when, i = 2

    //1 2               (thus, j = n - 3 = 2 elements: [1, 2])
    //_ _ _ _ _
    //0 1 x x x     -> when, i = 3

    //1                 (thus, j = n - 4 = 1 element: [1])
    //_ _ _ _ _
    //0 x x x x     -> when, i = 4
   


    //==================================================================
    

    // for (int i = 1; i <= n; i++) {
    //     cout << endl;

    //     for (int j = n; j > n - i; j--) {
    //         cout << i;
    //     }
    // }

    //#4: THE PROGRAM ABOVE RESULTS THIS ( TOOK TIME: 20 MINs )
    //1     (output: 1)
    //22    (output: 2)
    //333   (output: 3)
    //4444  (output: 4)
    //55555 (output: 5)


    //==================================================================


    // for (int i = 1; i <= n; i++) {
    //     cout << endl;

    //     for (int j = n; j > n - i; j--) {
    //     }
    // }

    //#5: THE PROGRAM ABOVE RESULTS THIS ( TOOK TIME: 25 MINs )
    //5             (when, j = 5)
    //_ _ _ _ _ 
    //1 x x x x                     -> thus, i = 1

    //5 4           (when, j = 4)
    //_ _ _ _ _ 
    //1 2 x x x                     -> i = 2

    //5 4 3         (when, j = 3)
    //_ _ _ _ _ 
    //1 2 3 x x                     -> i = 3

    //5 4 3 2       (when, j = 5)
    //_ _ _ _ _ 
    //1 2 3 4 x                     -> i = 4

    //5 4 3 2 1     (when, j = 5)
    //_ _ _ _ _ 
    //1 2 3 4 5                     -> i = 5

    
    //==================================================================


    for (int i = 1; i <= n; i++) {
        cout << endl;

        for (int j = 1; j <= n - (n - i); j++) { 
            cout << j;
        }
    }

    //#6: THE PROGRAM ABOVE RESULTS THIS ( TOOK THE LONGEST TIME: 2 HOURS 30 MINs MORE, HUAA :(( )
    //1                 (thus, j = n - (n-1) = 1 element: [1])
    //_ _ _ _ _
    //0 x x x x     -> when, i = 1 (at index = 0)

    //1 2               (thus, j = n - (n-2) = 2 elements: [1, 2])
    //_ _ _ _ _ 
    //0 1 x x x     -> when, i = 2 (at index = 1)

    //1 2 3             (thus, j = n - (n-3) = 2 elements: [1, 2, 3])
    //_ _ _ _ _ 
    //0 1 2 x x     -> when, i = 3 (at index = 2)

    //1 2 3 4           (thus, j = n - (n-4) = 4 elements: [1, 2, 3, 4])
    //_ _ _ _ _ 
    //0 1 2 3 x     -> when, i = 4 (at index = 3)

    //1 2 3 4 5         (thus, j = n - (n-5) = 5 elements: [1, 2, 3, 4, 5])
    //_ _ _ _ _
    //0 1 2 3 4     -> when, i = 5 (at index = 4)


    //==================================================================
}