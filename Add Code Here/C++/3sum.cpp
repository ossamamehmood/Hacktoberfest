 for (int i = 0; i < n; i++) {

        int currentSum = arr[i];

 

        if (currentSum == sum) {

            cout << "Sum found at indexes " << i << endl;

            return;

        }

        else {

            // Try all subarrays starting with 'i'

            for (int j = i + 1; j < n; j++) {

                currentSum += arr[j];

 

                if (currentSum == sum) {

                    cout << "Sum found between indexes "

                         << i << " and " << j << endl;

                    return;

                }

            }

        }

    }
