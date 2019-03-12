.name "Not A Chosen One"
.comment "Just another regular comment..."

code:		sti r1, %:live, %1 
			
live:		live %1
			zjmp %:live
			ld	%3, r3
			ld	%4, r4
			ld  %7, r7
			ld	%11, r11

load:		ldi %:code, %7, r9
			ldi %:code, %11, r10

replicate:	live %1
			sti r9, %:jump, r3
			sti r10, %:jump, r7 
			add r7, r4, r3
			add r3, r4, r7

carryon:	xor r4, r4, r8

			fork %:replicate
carryof:	and r15, r15, r15
jump:		zjmp %:code

