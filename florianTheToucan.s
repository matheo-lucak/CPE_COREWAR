	.name "Florian"
	.comment "It's florian and he is a Toucan ;)"

ld %0 r1
ld %1 r2
ld %33 r3
ld %0 r4
ld %8 r5
ld %9 r6
ld %-5 r7

add r1 r1 r1
fork %:florian_has_child_1

florian_wants_to_expand:
    live %33
    add r4 r5 r4
    sti r2 %24 r4
    sti r3 %22 r4
    sti r6 %17 r4
    sti r7 %13 r4
    add r1 r1 r1
    zjmp %:florian_wants_to_expand

florian_has_child_1:
    live %33