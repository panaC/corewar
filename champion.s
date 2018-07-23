.name		"les mlp's"
.comment	"Mark Lou Pierre"

live:		live %42
			ld :live, r10
			sti r10, %20, %0
			sti r1, %14, %0
			fork %:live
