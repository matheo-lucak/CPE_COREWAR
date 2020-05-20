	.name "Florian"
	.comment "It's florian and he is a Toucan ;)"

ld %33 r1
lld %16777216 r2
ld %33 r3
ld %0 r4
ld %8 r5
lld %218102528 r6
lld %-5 r7
ld %0 r16

add r16 r16 r16

florian_nursery:
    fork %:florian_wants_to_expand
    fork %:florian_has_child_1

florian_wants_to_expand:
    live %33
    add r4 r5 r4
    sti r2 %18 r4
    sti r3 %13 r4
    sti r6 %11 r4
    add r16 r16 r16
    zjmp %:florian_wants_to_expand

florian_has_child_1:
    live %33