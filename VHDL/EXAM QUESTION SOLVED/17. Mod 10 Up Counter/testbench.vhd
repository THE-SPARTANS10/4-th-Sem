library IEEE;
use IEEE.std_logic_1164.all;
 
entity testbench is
-- empty
end testbench; 

architecture tb of testbench is

-- DUT component
component asyn_3_bit_upcntr is
port(PRE,RST,CLK: in std_logic; Q: out std_logic_vector(3 downto 0));
end component;

signal CLK_i,PRE,RST: std_logic;
signal Q: std_logic_vector(3 downto 0);

begin

  -- Connect DUT
  DUT: asyn_3_bit_upcntr port map(PRE,RST,CLK_i,Q);
    process
    begin
      for i in 1 to 19 loop
        CLK_i<='0';
        wait for 1 ns;
        CLK_i<='1';
        wait for 1 ns;
    end loop;
    wait;
  end process;
  
  process 
  begin
  for i in 1 to 2 loop
  	PRE<='0';
  	RST<='1';
  	wait for 1 ns;
  
  	PRE<='0';
  	RST<='0';
  	wait for 18 ns;
  end loop;
  wait;
  end process;
end tb;