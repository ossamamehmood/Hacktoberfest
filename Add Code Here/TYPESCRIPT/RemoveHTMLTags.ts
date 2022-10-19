export class UtilityService {
	// Returns text without any tags
	static removeHtmlTags(fieldValue: any) {
	let pureText = fieldValue;
	const regex = /(<([^>]+)?>)/gi;

	if (fieldValue) {
	  pureText = pureText.toString().replace(regex, '');
	}

	return pureText;
	}
}

console.log(UtilityService.removeHtmlTags("<p>Title Value</p>")); // Title Value


