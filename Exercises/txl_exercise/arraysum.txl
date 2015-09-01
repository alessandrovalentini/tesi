define program
         [repeat number]
end define

function main
     replace [program]
	AR [repeat number]

    construct Result [number]
	0
    by
	Result [arraySum AR]	
end function

function arraySum AR [repeat number]
    deconstruct AR
	Head [number] Tail [repeat number]
    replace [number]
	N [number]
    by
	N[+ Head]
	 [arraySum Tail]
end function