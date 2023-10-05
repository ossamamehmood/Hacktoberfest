defmodule TreeNode do
  defstruct val: 0, left: nil, right: nil
end

defmodule Solution do
  def max_depth(nil), do: 0
  def max_depth(%TreeNode{left: left, right: right}) do
    1 + max(max_depth(left), max_depth(right))
  end
end