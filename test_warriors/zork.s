.name "zork"
.comment "I'M ALIIIIVE"

l2:		sti 0, %:live, %1
		and 0, %0, r1

live:	live %1
		zjmp %:live
