function permute(nums){
    const result = [];
    
    if (nums.length === 1) {
        return [nums];
    }
    
    for (let i = 0; i < nums.length; i++) {
        const current = nums[i];
        const remaining = [...nums].filter((num) => num != current);
        let perms = permute(remaining);
        
        for (let j = 0; j < perms.length; j++) {
            result.push([...perms[j], current])
        }
    }
    return result;
};