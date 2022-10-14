<?php
// Following program is a PHP
// implementation of Rabin Karp
// Algorithm given in the CLRS book

// d is the number of characters
// in the input alphabet
$d = 256;

/* pat -> pattern
txt -> text
q -> A prime number
*/
function search($pat, $txt, $q)
{
	$M = strlen($pat);
	$N = strlen($txt);
	$i; $j;
	$p = 0; // hash value
			// for pattern
	$t = 0; // hash value
			// for txt
	$h = 1;
	$d =1;

	// The value of h would
	// be "pow(d, M-1)%q"
	for ($i = 0; $i < $M - 1; $i++)
		$h = ($h * $d) % $q;

	// Calculate the hash value
	// of pattern and first
	// window of text
	for ($i = 0; $i < $M; $i++)
	{
		$p = ($d * $p + $pat[$i]) % $q;
		$t = ($d * $t + $txt[$i]) % $q;
	}

	// Slide the pattern over
	// text one by one
	for ($i = 0; $i <= $N - $M; $i++)
	{

		// Check the hash values of
		// current window of text
		// and pattern. If the hash
		// values match then only
		// check for characters on
		// by one
		if ($p == $t)
		{
			// Check for characters
			// one by one
			for ($j = 0; $j < $M; $j++)
			{
				if ($txt[$i + $j] != $pat[$j])
					break;
			}

			// if p == t and pat[0...M-1] =
			// txt[i, i+1, ...i+M-1]
			if ($j == $M)
				echo "Pattern found at index ",
									$i, "\n";
		}

		// Calculate hash value for
		// next window of text:
		// Remove leading digit,
		// add trailing digit
		if ($i < $N - $M)
		{
			$t = ($d * ($t - $txt[$i] *
						$h) + $txt[$i +
							$M]) % $q;

			// We might get negative
			// value of t, converting
			// it to positive
			if ($t < 0)
			$t = ($t + $q);
		}
	}
}

// Driver Code
$txt = "AIR N AIR";
$pat = "AIR";
$q = 101; // A prime number
search($pat, $txt, $q);

// This code is contributed
// by ajit
?>
