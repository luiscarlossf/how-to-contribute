.text
fibonacci:
	addi $a1,$a1,9
	addi $sp,$sp,-16
	sw $s0,12($sp) #x1
	sw $s1,8($sp) #x2
	sw $s2,4($sp) #aux
	sw $s3,0($sp) #i
	
	addi $s0,$s0,1
	addi $s1,$s1,1
	addi $s3,$s3,1
	
	loop:	
		add $s2,$s0,$zero
		add $s0,$s1,$zero
		add $s1,$s1,$s2
	
		li $v0,1           # service 1 is print integer
	    	add $a0,$s2,$zero  # load desired value into argument register $a0, using pseudo-op
		syscall
	
		addi $s3,$s3,1
		ble $s3,$a1,loop
	
	lw $s3,0($sp)
	lw $s2,4($sp)
	lw $s1,8($sp)
	lw $s0,12($sp)
	addi $sp,$sp,16