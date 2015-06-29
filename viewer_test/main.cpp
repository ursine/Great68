

/*

  create array of boxes mapped to memory, boxes are various shades of blue corresponding to their value.

  On read, set $FF to Green and decrement to 0 over the next 255 cycles

  On write, set $FF to Red and decrement to 0 over the next 255 cycles

  box

  #############################
  #       #         #         #
  #   65  #  01D3   #    B    #      
  #       #         #         #
  #############################
  #                           #
  #       42                  #
  #  binary version of value  #
  #                           #
  #   comment from docs about #
  #        purpose of addy    #
  ############################# 

 */



