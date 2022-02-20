/**
 * 如果一个序列 「有序」 且 「步长大致相同」 => 则 => 相比于二分查找，使用插值查找的效率更高
 * 
 * 插值查找的原理：
 * 
 *  ( 最大下标 - 最小下标 ) / ( 最大值 - 最小值 ) ≈ ( 目标下标 - 最小下标 ) / ( 目标值 - 最小值 )
 * 
 *  可推导出目标下标的大致落点
 * 
 *  后续操作与二分查找相同
 */