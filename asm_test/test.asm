.intel_syntax noprefix

.section .data
	result: .long 0
	to_add: .long 1,4,5,3,4,3,0
	to_add_index: .long 0

.section .text
.globl _start

_start:
	JMP _push_to_stack_loop

_push_to_stack_loop:
	MOV EBX, [to_add_index]			# load to_add_index into ebx
	MOV EAX, [to_add + EBX*4]		# load to_add[ebx(to_add_index)] into eax
	CMP EAX, 0				# if EAX is zero ...
	JE _everything_on_stack			# jump to _everything_on_stack
	PUSH EAX				# push eax(to_add[to_add_index]) onto the stack
	MOV ebx, [to_add_index]			# Increment to_add_index by 1
	INC ebx					# ...
	MOV [to_add_index], ebx			# ...
	JMP _push_to_stack_loop			# Go to start of loop
	
_everything_on_stack:
	MOV EBX, [to_add_index]			# substract one from to_add_index
	DEC EBX					# ...
	MOV [to_add_index], EBX			# ...
	CMP EBX, 0				# if EBX < 0
	JL end					# jump to end
	POP EAX
	ADD [result], EAX
	JMP _everything_on_stack

end:
	MOV EAX, 1				# sys_exit call
	MOV EBX, [result] 			# move result into ebx (status code)
	INT 0x80				# kernel interrupt
