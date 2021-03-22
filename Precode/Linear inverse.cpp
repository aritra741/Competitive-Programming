inv[1] = 1;
	for ( int i = 2; i < mx; i++ ) {
		inv[i] = (-(mod / i) * inv[mod % i] ) % mod;
		inv[i] = inv[i] + mod;
	}