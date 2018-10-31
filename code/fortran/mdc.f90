h1 = 2*n + m
h2 = 2*m + n

DO WHILE (h1/=h2)

	IF(h1 > h2) THEN
	c = h1 - h2
	h1 = c
	
	END IF
END DO

t1 = (2*m+n)/h1
t2 = (2*n+m)/h1

PRINT*, t1, t2
